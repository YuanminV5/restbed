/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _RESTBED_STRING_H
#define _RESTBED_STRING_H 1

//System Includes
#include <map>
#include <string>
#include <vector>
#include <cstdarg>

//Project Includes
#include <corvusoft/restbed/byte.hpp>

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    
    class String
    {
        public:
            //Friends
            
            //Definitions
            enum Option : int
            {
                CASE_SENSITIVE = 0,
                CASE_INSENSITIVE = 1
            };
            
            //Constructors
            
            //Functionality
            static Bytes to_bytes( const std::string& value );
            
            static std::string to_string( const Bytes& value );
            
            static std::string lowercase( const std::string& value );
            
            static std::string uppercase( const std::string& value );
            
            static std::string format( const char* format, ... );
            
            static std::vector< std::string > split( const std::string& text, const char delimiter );
            
            static std::string join( const std::multimap< std::string, std::string >& values, const std::string& pair_delimiter, const std::string& delimiter );
            
            static std::string trim( const std::string& value, const std::string& delimiter = " \t\r\n" );
            
            static std::string remove( const std::string& needle, const std::string& haystack, const Option option = CASE_SENSITIVE );
            
            static std::string replace( const std::string& target, const std::string& substitute, const std::string& value, const Option option = CASE_SENSITIVE );

            //Getters
            
            //Setters
            
            //Operators
            
            //Properties
            
        protected:
            //Friends
            
            //Definitions
            
            //Constructors
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            
            //Properties
            
        private:
            //Friends
            
            //Definitions
            
            //Constructors
            String( void ) = delete;
            
            String( const String& original ) = delete;
            
            virtual ~String( void ) = delete;
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            String& operator =( const String& value ) = delete;
            
            //Properties
    };
}

#endif  /* _RESTBED_STRING_H */