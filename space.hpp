#ifndef SPACE
#define SPACE

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>

namespace space
{
  namespace
  {
     std::stringstream str;
    std::map<std::string, std::map<std::string, std::string> > data;
    void save()
    {
      std::ofstream file("data.json");
      file << "{\n";
      for (std::map<std::string, std::map<std::string, std::string> >::iterator entry = data.begin(); entry != data.end(); entry++)
      {
        file << "  "
             << "\"" << entry->first << "\""
             << ": "
             << "{\n"
             << "    "
             << "\"type\""
             << ": "
             << "\"" << entry->second["type"] << "\""
             << ",\n"
             << "    "
             << "\"data\""
             << ": "
             << "[\n"
             << entry->second["data"];
        file.seekp(-3, std::ios::cur);
        file << "\n"
             << "    "
             << "]\n"
             << "  "
             << "}"
             << ",\n";
      }      
      file.seekp(-3, std::ios::cur);
      file << "\n}";
      file.close();
    }
    class space
    {
    public:
      space()
      {
        std::atexit(save);
      }
    } space;
  }

  void sout(std::string name, int array[], int size)
  { 
    str.str("");
    data[name]["type"] = "Array1D";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  void sout(std::string name, double array[], int size)
  {
    str.str("");
    data[name]["type"] = "Array1D";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  void sout (std::string name, float array[], int size){
    str.str("");
    data[name]["type"] = "Array1D";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  void sout (std::string name, char array[], int size){
    str.str("");
    data[name]["type"] = "Array1D";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << "\""<<  array[i] << "\"" << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  void sout (std::string name, bool array[], int size){
    str.str("");
    data[name]["type"] = "Array1D";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

}

#endif
