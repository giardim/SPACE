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
};

std::map<std::string, std::map<std::string, std::string> > space::data;
std::stringstream space::dstream, space::istream;
space space::s;

#endif
