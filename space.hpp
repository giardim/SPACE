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
      for (std::map<std::string, std::map<std::string, std::string> >::iterator key = data.begin(); key != data.end(); key++)
      {
        file << "  "
             << "\"" << key->first << "\""
             << ": "
             << "{\n"
             << "    "
             << "\"type\""
             << ": "
             << "\"" << key->second["type"] << "\""
             << ",\n"
             << "    "
             << "\"data\""
             << ": "
             << "[\n"
             << key->second["data"];
        file.seekp(-2, std::ios::cur);
        file << "\n"
             << "    "
             << "]\n"
             << "  "
             << "}"
             << ",\n";
      }
      file.seekp(-2, std::ios::cur);
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
    for (size_t i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
  }
}

#endif
