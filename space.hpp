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
    std::stringstream indices;
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
             << "\"is_char\""
             << ": "
             << entry->second["is_char"]
             << ",\n"
             << "    "
             << "\"indices\""
             << ": "
             << "["
             << entry->second["indices"];
             #ifdef _WIN32             
        file.seekp(-3, std::ios::cur);
#else
        file.seekp(-2, std::ios::cur);
#endif // WIN32

             file << "\n"
             << "],"
             << "    "
             << "\"data\""
             << ": "
             << "[\n"
             << entry->second["data"];
#ifdef _WIN32             
        file.seekp(-3, std::ios::cur);
#else
        file.seekp(-2, std::ios::cur);
#endif // WIN32
        file << "\n"
             << "    "
             << "]\n"
             << "  "
             << "}"
             << ",\n";
      }
      #ifdef _WIN32             
        file.seekp(-3, std::ios::cur);
#else
        file.seekp(-2, std::ios::cur);
#endif // WIN32
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

  //Passed tests
  void sout(std::string name, int array[], int size)
  {
    str.str("");
    indices.str("");
    indices << "";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str();
  }

  //Passed tests
  void sout(std::string name, int array[], int size, int i, int j)
  {
    str.str("");
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str() + ",\n";
  }

  //Passed tests
  void sout(std::string name, double array[], int size)
  {
    str.str("");
    indices.str("");
    indices << "";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str();
  }

  //Passed tests
  void sout(std::string name, double array[], int size, int i, int j)
  {
    str.str("");
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str() + ",\n";
  }

  //Passed tests
  void sout(std::string name, float array[], int size)
  {
    str.str("");
    indices.str("");
    indices << "";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str();
  }

  //Passed tests
  void sout(std::string name, float array[], int size, int i, int j)
  {
    str.str("");
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str() + ",\n";
  }

  //Passed tests
  void sout(std::string name, char array[], int size)
  {
    str.str("");
    indices.str("");
    indices << "";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str();
  }

  //Passed tests
  void sout(std::string name, char array[], int size, int i, int j)
  {
    str.str("");
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str() + ",\n";
  }

  //Passed Tests
  void sout(std::string name, bool array[], int size)
  {
    str.str("");
    indices.str("");
    indices << "";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str();
  }

  //Passed Tests
  void sout(std::string name, bool array[], int size, int i, int j)
  {
    str.str("");
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? "," : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "     " + indices.str() + ",\n";
  }
}

#endif
