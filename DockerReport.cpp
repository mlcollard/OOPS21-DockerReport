/*
    DockerReport.cpp

    Produces a report with various counts of the parts
    of a DockerCompose file.

    Input is an YAML file in the Docker Compose format.

    Limitations:
    * Much of YAML is not supported
*/

#include <iostream>

#include "ParserEngine.hpp"
#include "DockerReportHandler.hpp"

int main() {

    // parse dockercompose.yml on standard input
    DockerReportHandler handler;
    goParse(handler);

    // Docker Compose report
    std::cout << "# Docker Report: version " << handler.getVersion() << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << handler.getKeyCount() << " |\n";
    std::cout << "| ubuntu | " << handler.getUbuntuCount() << " |\n";
    std::cout << "| fedora | " << handler.getFedoraCount() << " |\n";
    std::cout << "| centos | " << handler.getCentOSCount() << " |\n";
    std::cout << "| opensuse | " << handler.getOpenSuseCount() << " |\n";

    return 0;
}
