/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 *
 * http://corvusoft.co.uk/license
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _RESTBED_LOGGER_H
#define _RESTBED_LOGGER_H 1

//System Includes
#include <string>
#include <memory>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    class Settings;

    class Logger
    {
        public:
            //Friends
            
            //Definitions
            enum Level : int
            {
                INFO = 0000,
                DEBUG = 1000,
                FATAL = 2000,
                ERROR = 3000,
                WARNING = 4000,
                SECURITY = 5000
            };
            
            //Constructors
            
            //Functionality
            virtual void stop( void ) = 0;

            virtual void start( const std::shared_ptr< const Settings >& settings ) = 0;

            virtual void log( const Level level, const std::string format, ... ) = 0;
            
            virtual void log_if( bool expression, const Level level, const std::string format, ... ) = 0;
            
            //Getters
            
            //Setters
            
            //Operators
            
            //Properties
            
        protected:
            //Friends
            
            //Definitions
            
            //Constructors
            Logger( void ) = default;
            
            Logger( const Logger& original ) = default;
        
            virtual ~Logger( void ) = default;
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            Logger& operator =( const Logger& value ) = default;
            
            //Properties
            
        private:
            //Friends
            
            //Definitions
            
            //Constructors
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            
            //Properties
    };
}

#endif  /* _RESTBED_LOGGER_H */
