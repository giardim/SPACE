#ifndef SPACE
#define SPACE

#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>

namespace space
{
  namespace
  {
    std::stringstream str;
    std::stringstream indicies;
    std::map<std::string, std::map<std::string, std::string> > data;
    void save()
    {
      std::ofstream file("data.json");
      file << "{\r\n";
      for (std::map<std::string, std::map<std::string, std::string> >::iterator entry = data.begin(); entry != data.end(); entry++)
      {
        file << "  "
             << "\"" << entry->first << "\""
             << ": "
             << "{\r\n"
             << "    "
             << "\"type\""
             << ": "
             << "\"" << entry->second["type"] << "\""
             << ",\r\n"
             << "    "
             << "\"is_char\""
             << ": "
             << entry->second["is_char"]
             << ",\r\n"
             << "    "
             << "\"indicies\""
             << ": "
             << "["
             << entry->second["indicies"]
             << "\r\n"
             << "],"
             << "    "
             << "\"data\""
             << ": "
             << "[\r\n"
             << entry->second["data"];
        file.seekp(-3, std::ios::cur);
        file << "\r\n"
             << "    "
             << "]\r\n"
             << "  "
             << "}"
             << ",\r\n";
      }
      file.seekp(-3, std::ios::cur);
      file << "\r\n}";
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
    data[name]["data"] += "      " + str.str() + ",\r\n";
  }

  void sout(std::string name, int array[], int size, int i, int j)
  {
    str.str("");
    indicies.str("");
    indicies << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\r\n";
    data[name]["indicies"] += "     " + indicies.str() + ",\r\n";
  }

  void sout(std::string name, double array[], int size)
  {
    str.str("");
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\r\n";
  }

  void sout(std::string name, float array[], int size)
  {
    str.str("");
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\r\n";
  }

  void sout(std::string name, char array[], int size)
  {
    str.str("");
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\r\n";
  }

  void sout(std::string name, bool array[], int size)
  {
    str.str("");
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\r\n";
  }
}

#endif
