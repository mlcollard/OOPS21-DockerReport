/*
    DockerReport.cpp

    Produces a report with various counts of the parts
    of a DockerCompose file.

    Input is an YAML file in the Docker Compose format.

    Limitations:
    * Much of YAML is not supported
*/

#include <iostream>
#include <string>

#include "DockerReportParser.hpp"

int main() {

    // parse the YAML dockercompose.yml on standard input
    DockerReportParser parser;
    parser.parse();

    // Docker Compose report
    std::cout << "# Docker Report: version " << parser.getVersion() << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << parser.getKeyCount() << " |\n";
    std::cout << "| ubuntu | " << parser.getUbuntuCount() << " |\n";
    std::cout << "| fedora | " << parser.getFedoraCount() << " |\n";
    std::cout << "| centos | " << parser.getCentOSCount() << " |\n";
    std::cout << "| opensuse | " << parser.getOpenSuseCount() << " |\n";

    return 0;
}
