#ifndef LIFE_EXPORTER_H
#define LIFE_EXPORTER_H

#include "../stuff.h"
#include "../Game/Condition.h"
#include "ConsExport.h"

namespace LifeGame{
     class FileExport: public ConsExport{
         string fileName;
         void fieldOut(std::ofstream &out);
     public:
         FileExport();
         FileExport(const FileExport& other);
         FileExport& operator=(const FileExport& other);
         FileExport(Condition finish, string name);
         ~FileExport();
         void saveToFile();
     };
 };
#endif //LIFE_EXPORTER_H
