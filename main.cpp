#include "config.hpp"
#include <algorithm>
#include <cctype>


namespace fs = std::filesystem;

int main(){

    fs::path currentPath = fs::current_path();
    fs::path destinationFolderImage = currentPath / "image";
    fs::path destinationFolderVideo = currentPath / "video";
    fs::path destinationFolderProgramWin = currentPath / "programWindow";
    fs::path destinationFolderTxt = currentPath / "txt";
    fs::path destinationFolderZip = currentPath / "zip";
    fs::path destinationFolderIso = currentPath / "iso";

    std::unordered_map<std::string, std::string> commands = {
        {".png",  destinationFolderImage  },
        {".jpg",  destinationFolderImage  },
        {".jpeg",  destinationFolderImage  },
        {".mov",  destinationFolderImage  },
        {".gif",  destinationFolderImage  },

        {".exe",  destinationFolderProgramWin },

        {".txt",  destinationFolderTxt  },

        {".mp4",  destinationFolderVideo  },
        {".avi",  destinationFolderVideo  },
        {".mov",  destinationFolderVideo  },
        
        {".zip",  destinationFolderZip  },
        {".gz",  destinationFolderZip  },
        {".7z",  destinationFolderZip  },
        {".rar",  destinationFolderZip  },
        {".tar",  destinationFolderZip  },

        {".iso",  destinationFolderIso  },
    };


    for (const auto& entry : fs::directory_iterator(currentPath)) {
        for (const auto& [command, pathToFolderRight] : commands) {

            std::string commandUp = command;
            std::transform(commandUp.begin(), commandUp.end(), commandUp.begin(), [](unsigned char c) { return std::toupper(c); });

            if(entry.path().extension() == command || entry.path().extension() == commandUp){
                if (!fs::exists(pathToFolderRight)) {
                    fs::create_directory(pathToFolderRight);
                }
                fs::path newLocation = pathToFolderRight / entry.path().filename();
                fs::rename(entry.path(),   newLocation );

                std::cout << entry.path().filename() << " moved to " << pathToFolderRight << "\n";
            }
        }
    }


    return 0;
}
