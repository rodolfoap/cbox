#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)
#define fwrite(file, data){std::ofstream f; f.open(file); f<<data; f.close();}
