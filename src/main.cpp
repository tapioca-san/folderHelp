#include "config.hpp"


namespace fs = std::filesystem;

int main(){

    fs::path currentPath = fs::current_path();
    fs::path destinationFolderImage = currentPath / "image";
    fs::path destinationFolderVideo = currentPath / "video";
    fs::path destinationFolderProgramWin = currentPath / "programWindow";
    fs::path destinationFolderTxt = currentPath / "txt";
    fs::path destinationFolderZip = currentPath / "zip";
    fs::path destinationFolderIso = currentPath / "iso";
    fs::path destinationFolderMusic = currentPath / "music";
    fs::path destinationFolderProjectAE = currentPath / "projectAE";
    fs::path destinationModelThreeD = currentPath / "model3D";
    fs::path destinationVirtualBox = currentPath / "VirtualBoxIso";
    fs::path destinationFlatPak = currentPath / "FlatPakFiles";
    fs::path destinationJson = currentPath / "JsonFiles";
    fs::path destinationFont = currentPath / "TextFont";

    std::unordered_map<std::string, std::string> commands = {
        {".png",  destinationFolderImage  },
        {".jpg",  destinationFolderImage  },
        {".jpeg",  destinationFolderImage  },
        {".mov",  destinationFolderImage  },
        {".gif",  destinationFolderImage  },
        {".webp",  destinationFolderImage  },

        {".exe",  destinationFolderProgramWin },

        {".txt",  destinationFolderTxt  },

        {".mp4",  destinationFolderVideo  },
        {".avi",  destinationFolderVideo  },
        {".mov",  destinationFolderVideo  },

        {".wav",  destinationFolderMusic  },
        {".aiff",  destinationFolderMusic  },
        {".mp3",  destinationFolderMusic  },
        {".ogg",  destinationFolderMusic  },
        {".m4a",  destinationFolderMusic  },
        
        {".zip",  destinationFolderZip  },
        {".gz",  destinationFolderZip  },
        {".7z",  destinationFolderZip  },
        {".rar",  destinationFolderZip  },
        {".tar",  destinationFolderZip  },

        {".iso",  destinationFolderIso  },
        
        {".aep",  destinationFolderProjectAE  },


        {".obj",  destinationModelThreeD  },

        {".glb",  destinationModelThreeD  },
        {".fbx",  destinationModelThreeD  },
        {".stl",  destinationModelThreeD  },
        
        {".ova",  destinationVirtualBox  },

        {".flatpakref",  destinationFlatPak  },

        {".json",  destinationJson  },

        {".ttf",  destinationFont  },
        
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
