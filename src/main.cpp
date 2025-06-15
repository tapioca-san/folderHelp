#include "config.hpp"
#include <filesystem>


namespace fs = std::filesystem;

std::string FolderName = "organizado";


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
    fs::path destinationPdf = currentPath / "PDF";
    fs::path destinationDocx = currentPath / "Docx";
    fs::path destinationHtml = currentPath / "HTML";
    fs::path destinationCss = currentPath / "CSS";
    fs::path destinationTorrent = currentPath / "Torrent";


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

        {".pdf",  destinationPdf  },
        {".docx",  destinationDocx  },
        {".html",  destinationHtml  },
        {".css",  destinationCss  },
        {".torrent",  destinationTorrent  },

        
    };

    if (!fs::exists(FolderName)) { // criar pasta onde fica guardado tudo
        fs::create_directory(FolderName);
    }
        
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        for (const auto& [command, pathToFolderRight] : commands) {

            std::string commandUp = command;
            std::transform(commandUp.begin(), commandUp.end(), commandUp.begin(), [](unsigned char c) { return std::toupper(c); });

            if(entry.path().extension() == command || entry.path().extension() == commandUp){
                if (!fs::exists(FolderName + "/" + pathToFolderRight)) {
                    fs::create_directory(FolderName + "/" +  pathToFolderRight);
                }
                fs::path newLocation = (FolderName + "/" + pathToFolderRight) / entry.path().filename();
                fs::rename(entry.path(),newLocation );

            }
        }
    }


    return 0;
}
