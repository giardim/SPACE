#ifndef SPACE
#define SPACE

#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>

class space
{
private:
  space() { std::atexit(save); };
  ~space(){};
  space(const space &);
  space &operator=(const space &);

  static std::map<std::string, std::map<std::string, std::string> > data;
  static std::stringstream dstream, istream;
  static space s;

  static void save()
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

public:
  static void sout(std::string name, bool array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, bool array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, char array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, char array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, double array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, double array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, float array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, float array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, int array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, int array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, wchar_t array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, wchar_t array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << i << ", " << j << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }
};

std::map<std::string, std::map<std::string, std::string> > space::data;
std::stringstream space::dstream, space::istream;
space space::s;

#endif
