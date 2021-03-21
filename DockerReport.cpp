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

    std::string version;
    bool inversion = false;
    int key_count = 0;
    int ubuntu_count = 0;
    int fedora_count = 0;
    int centos_count = 0;
    int opensuse_count = 0;

    // parse the YAML dockercompose.yml on standard input
    DockerReportParser parser;
    parser.setKeyHandler(

        [&](const std::string& name) {

            // update docker counters and version
            if (name == "version") {
                inversion = true;
            } else {
                ++key_count;
                std::string name_prefix = name.substr(0, name.find('_'));
                if (name_prefix == "ubuntu") {
                    ++ubuntu_count;
                } else if (name_prefix == "fedora") {
                    ++fedora_count;
                } else if (name_prefix == "centos") {
                    ++centos_count;
                } else if (name_prefix == "opensuse") {
                    ++opensuse_count;
                }
            }
        }
    );
    parser.setValueHandler(

        [&inversion,&version](const std::string& value) {

            // save the version value
            if (inversion) {
                version = value;
                inversion = false;
            }
        }
    );
    parser.parse();

    // Docker Compose report
    std::cout << "# Docker Report: version " << parser.getVersion() << '\n';
    std::cout << "| Platform | Count |\n";
    std::cout << "|:-----|-----:|\n";
    std::cout << "| all | " << key_count << " |\n";
    std::cout << "| ubuntu | " << ubuntu_count << " |\n";
    std::cout << "| fedora | " << fedora_count << " |\n";
    std::cout << "| centos | " << centos_count << " |\n";
    std::cout << "| opensuse | " << opensuse_count << " |\n";

    return 0;
}
