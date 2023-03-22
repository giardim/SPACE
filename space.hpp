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
             << "[\n"
             << entry->second["indices"];

#ifdef _WIN32
        file.seekp(-3, std::ios::cur);
#else
        file.seekp(-2, std::ios::cur);
#endif

        file << "\n"
             << "    "
             << "],\n"
             << "    "
             << "\"data\""
             << ": "
             << "[\n"
             << entry->second["data"];

#ifdef _WIN32
        file.seekp(-3, std::ios::cur);
#else
        file.seekp(-2, std::ios::cur);
#endif

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
#endif

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

  // passed tests
  void sout(std::string name, bool array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, bool array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, char array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, char array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, double array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, double array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, float array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, float array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, int array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, int array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, wchar_t array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  // passed tests
  void sout(std::string name, wchar_t array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << i << ", " << j << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; i++)
    {
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }
}

#endif
