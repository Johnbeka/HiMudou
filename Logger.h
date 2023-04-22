#pragma once

#include <string>
// 定义日志级别 INFO（正常日志输出，正常流程） ERROR（错误不影响软件正常执行）  FATAL（出现软件不能正常运行的错误） DEBUG （调试的时候才开启的日志）


enum LogLevel
{
    INFO,
    ERROR,
    FATAL,
    DEBUG
};

#define LOGINFO(logFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance();\
        logger.setLevel(INFO);\
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logFormat, ##_VA_ARGS__);\
        logger.log(buf);\
    }while (0);

#define LOGERROR(logFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance();\
        logger.setLevel(ERROR);\
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logFormat, ##_VA_ARGS__);\
        logger.log(buf);\
    }while (0);

#define LOGFATAL(logFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance();\
        logger.setLevel(FATAL);\
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logFormat, ##_VA_ARGS__);\
        logger.log(buf);\
    }while (0);

#ifdef MUDEBUG
#define LOGDEBUG(logFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance();\
        logger.setLevel(DEBUG);\
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logFormat, ##_VA_ARGS__);\
        logger.log(buf);\
    }while (0);
#else
#define LOGDEBUG(LogFormat, ...)
#endif

class Logger
{
public:
    static Logger& instance();

    //设置日志级别
    void setLogLevel(int loglevel);

    void log(std::string msg);

private:
    int logLevel_;
    Logger(){};

};
















