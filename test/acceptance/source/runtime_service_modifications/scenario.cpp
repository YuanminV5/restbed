/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <thread>
#include <string>
#include <memory>
#include <chrono>
#include <stdexcept>
#include <functional>

//Project Includes
#include <restbed>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::thread;
using std::string;
using std::function;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;
using std::chrono::seconds;

//Project Namespaces
using namespace restbed;

//External Namespaces

void handler( const shared_ptr< Session >& )
{
    return;
}

void error_handler( const int, const shared_ptr< Session >& )
{
    return;
}

void authentication_handler( const shared_ptr< Session >&, const function< void ( const shared_ptr< Session >& ) >& )
{
    return;
}

void wait_for_service_initialisation( void )
{
    std::this_thread::sleep_for( seconds( 1 ) );
}

SCENARIO( "runtime service modifications", "[service]" )
{
    GIVEN( "I publish a resource at '/resources/1' with a HTTP 'GET' method handler" )
    {
        auto settings = make_shared< Settings >( );
        settings->set_port( 1984 );

        Service service;
        thread service_thread( [ &service, settings ] ( )
        {
            service.start( settings );
        } );

        wait_for_service_initialisation( );

        WHEN( "I attempt to modify service settings" )
        {
            auto resource = make_shared< Resource >( );
            resource->set_path( "/acceptance-tests/runtime service modifications" );

            THEN( "I should see an runtime error of 'Runtime modifications of the service are prohibited.'" )
            {
                REQUIRE_THROWS_AS( service.publish( resource ), runtime_error );
                REQUIRE_THROWS_AS( service.suppress( resource ), runtime_error );
                REQUIRE_THROWS_AS( service.set_logger( nullptr ), runtime_error );
                REQUIRE_THROWS_AS( service.set_not_found_handler( handler ), runtime_error );
                REQUIRE_THROWS_AS( service.set_error_handler( error_handler ), runtime_error );
                REQUIRE_THROWS_AS( service.set_method_not_allowed_handler( handler ), runtime_error );
                REQUIRE_THROWS_AS( service.set_method_not_implemented_handler( handler ), runtime_error );
                REQUIRE_THROWS_AS( service.set_failed_filter_validation_handler( handler ), runtime_error );
                REQUIRE_THROWS_AS( service.set_authentication_handler( authentication_handler ), runtime_error );
            }
        }
        
        service.stop( );
        service_thread.join( );
    }
}
