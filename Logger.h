//
// Created by Ali Hamdy on 06/11/2025.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    Logger();
    ~Logger();
    void SetMessage(int type , const char *text , va_list args);

private:
     typedef struct Logging{
        const char *Message;
        int type;
        time_t CurrTime;
        va_list args;
    }LOG;
    LOG Log;
    void WriteLog(int type , const char *text , va_list args);
};



#endif //LOGGER_H
