#ifndef SPACE
#define SPACE

#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <queue>


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

  //Algorithms
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
  //Data structures
  void sout (std::string name, std::string &type, int array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::string &type, double array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::string &type, char array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::string &type, boolean array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::string &type, float array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "0";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::string &type, wchar_t array[], int size){
    std::string fixedType = "";
    for (int i = 0; i < type.length(); ++i){
      fixedType += char(std::tolower(type[i]));
      }

  
    while (fixedType != "stack" && fixedType != "queue" && fixedType != "dequeue"){
      fixedType = "";
      type = "";
      std::cout << "You did not enter a valid data structure, please indicate if you are visualizing";
      std::cout << "a 'stack', 'queue', or 'dequeue': ";
      std::cin >> fixedType;

      for (int i = 0; i < type.length(); ++i){
        fixedType += char(std::tolower(type[i]));
      }

      type = fixedType;
      std::cout << fixedType << " " << type << "\n";
    }

    data[name]["type"] = fixedType;
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < size; ++i){
      str << (int)array[i] << (i < size - 1 ? ", " : "");
    }
    str << "]";
    data[name]["data"] += "      " + str.str() + ",\n";
    data[name]["indices"] += "      " + indices.str() + ",\n";
  }

  void sout (std::string name, std::stack<int> stack){
    int initSize = stack.size();
    data[name]["type"] = "stack";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < initSize; i++)
    {
      str << stack.top() << (i < initSize - 1 ? ", " : "");
      stack.pop();
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

  void sout (std::string name, std::queue<int> queue){
    int initSize = queue.size();
    data[name]["type"] = "queue";
    data[name]["is_char"] = "1";
    indices.str("");
    indices << "[" << -1 << ", " << -1 << "]";
    str.str("");
    str << "[";
    for (int i = 0; i < initSize; i++)
    {
      str << queue.front() << (i < initSize - 1 ? ", " : "");
      queue.pop();
    }
    str << "]";
    data[name]["indices"] += "      " + indices.str() + ",\n";
    data[name]["data"] += "      " + str.str() + ",\n";
  }

}



#endif
