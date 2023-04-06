#ifndef SPACE
#define SPACE

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <queue>
#include <list>
#include <iostream>

class space
{
public:
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
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, bool array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, char array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, char array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, double array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, double array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, float array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, float array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, int array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, int array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, wchar_t array[], int size)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, wchar_t array[], int size, int i, int j)
  {
    data[name]["type"] = "Array1D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[" << i << ", " << j << "]"
            << ",\n";
    dstream.str("");
    dstream << "      "
            << "[";
    for (int i = 0; i < size; i++)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]"
            << ",\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, bool (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, bool **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, bool (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, bool **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, char (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, char **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, char (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, char **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, double (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, double **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, double (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, double **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, float (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, float **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, float (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, float **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, int (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, int **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, int (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, int **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, wchar_t (&array)[row][col], int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, wchar_t **array, int rows, int cols)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << ",\n"
            << "        "
            << "[" << -1 << ", " << -1 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  template <int row, int col>
  static void sout(std::string name, wchar_t (&array)[row][col], int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, wchar_t **array, int rows, int cols, int i10, int i00, int i11, int i01)
  {
    data[name]["type"] = "Array2D";
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "      "
            << "[\n"
            << "        "
            << "[" << i10 << ", " << i00 << "]"
            << ",\n"
            << "        "
            << "[" << i11 << ", " << i01 << "]"
            << "\n"
            << "      "
            << "],\n";
    dstream.str("");
    dstream << "      "
            << "[\n";
    for (int r = 0; r < rows; r++)
    {
      dstream << "        "
              << "[";
      for (int c = 0; c < cols; c++)
      {
        dstream << (int)array[r][c] << (c < cols - 1 ? ", " : "");
      }
      dstream << "]"
              << (r < rows - 1 ? ",\n" : "\n");
    }
    dstream << "      "
            << "],\n";
    data[name]["indices"] += istream.str();
    data[name]["data"] += dstream.str();
  }

  static void sout(std::string name, std::string &type, int array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::string &type, double array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::string &type, char array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::string &type, bool array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::string &type, float array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::string &type, wchar_t array[], int size)
  {
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i)
    {
      fixedType += char(std::tolower(type[i]));
    }

    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue")
    {
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i)
      {
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "1";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < size; ++i)
    {
      dstream << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["data"] += "      " + dstream.str() + ",\n";
    data[name]["indices"] += "      " + istream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<int> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<float> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<double> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<bool> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "0";
    istream.str("");
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<char> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::stack<wchar_t> stack)
  {
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<int> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << "[" << -1 << ", " << -1 << "]";
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<float> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << "[" << -1 << ", " << -1 << "]";
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<double> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << "[" << -1 << ", " << -1 << "]";
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<bool> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << "[" << -1 << ", " << -1 << "]";
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<char> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)queue.front() << (i < initSize - 1 ? ", " : "");
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::queue<wchar_t> queue)
  {
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)queue.front() << (i < initSize - 1 ? ", " : "");
      queue.pop();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::list<int> list)
  {
    int initSize = list.size();
    data[name]["type"] = "list";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << list.front() << (i < initSize - 1 ? ", " : "");
      list.pop_front();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::list<float> list)
  {
    int initSize = list.size();
    data[name]["type"] = "list";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << list.front() << (i < initSize - 1 ? ", " : "");
      list.pop_front();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::list<double> list)
  {
    int initSize = list.size();
    data[name]["type"] = "list";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << list.front() << (i < initSize - 1 ? ", " : "");
      list.pop_front();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::list<bool> list)
  {
    int initSize = list.size();
    data[name]["type"] = "list";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << list.front() << (i < initSize - 1 ? ", " : "");
      list.pop_front();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::list<char> list)
  {
    int initSize = list.size();
    data[name]["type"] = "list";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)list.front() << (i < initSize - 1 ? ", " : "");
      list.pop_front();
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<int> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<double> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<float> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<bool> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<char> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<wchar_t> vector)
  {
    int initSize = vector.size();
    data[name]["type"] = "1DVector";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < initSize; i++)
    {
      dstream << (int)vector[i] << (i < initSize - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<int> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<float> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<double> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<bool> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<char> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "1";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << (int)vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
    }
    dstream << "]";
    data[name]["indices"] += "      " + istream.str() + ",\n";
    data[name]["data"] += "      " + dstream.str() + ",\n";
  }

  static void sout(std::string name, std::vector<std::vector<wchar_t> > vector)
  {
    data[name]["type"] = "2DVector";
    data[name]["is_char"] = "0";
    istream.str();
    istream << "[" << -1 << ", " << -1 << "]";
    dstream.str("");
    dstream << "[";
    for (int i = 0; i < vector.size(); i++)
    {
      dstream << "[";
      for (int j = 0; j < vector[i].size(); ++j)
      {
        dstream << vector[i][j] << (j < vector[i].size() - 1 ? ", " : "");
      }
      dstream << "]";
      dstream << (i < vector.size() - 1 ? ", " : "");
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
