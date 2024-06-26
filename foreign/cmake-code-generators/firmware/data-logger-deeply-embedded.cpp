#include <sink-composite.h>
#include <sink-terminal.h>

#include <project-config.h>
#if HAVE_SQLITE3==1
#  include <sink-sqlite3.h>
#endif
#if HAVE_MOSQUITTO==1
#  include <sink-mqtt.h>
#endif

#include <data-logger.h>

#include "conf-sensors.h"        // <--- THE extern declaration

#include <memory>
#include <iostream>


int main(int argc, char** argv)
{
#   ifdef HAVE_SQLITE3
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <SQLITE3-DB>" << std::endl;
        std::cerr << "  (Create: \"" << SinkSQLite3::create_table_statement << "\")" << std::endl;
        return 1;
    }

    std::string dbfile = argv[1];
#   endif

    std::cerr << "Running version " << GLUEHWEINKOCHEN_MAJOR << '.' << GLUEHWEINKOCHEN_MINOR << std::endl;

    auto sink = std::make_unique<SinkComposite>();

    sink->add_sink(std::make_unique<SinkTerminal>());
#   ifdef HAVE_SQLITE3    
    sink->add_sink(std::make_unique<SinkSQLite3>(dbfile));
#   endif
#   ifdef HAVE_MOSQUITTO
    sink->add_sink(std::make_unique<SinkMQTT>("localhost", 1883, "gluehwein"));
#   endif

    DataLogger logger(conf_sensors, std::move(sink), 1000/*ms*/);
    logger.start_logging();

    return 0;
}
