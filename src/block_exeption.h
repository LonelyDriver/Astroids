#ifndef _BLOCK_EXCEPTION_H
#define _BLOCK_EXCEPTION_H
#include <stdexcept>

namespace block {
    class BlockException : public std::exception {
    private:
        const char* _msg;
        const char* _file;
        int _line;
        const char* _info;
        int _error_code;
    public:
        BlockException(
            const char* msg,
            const char* file,
            int line,
            int error_code,
            const char* info=""
        ) : std::exception(),
        _msg(msg),
        _file(file),
        _line(line),
        _info(info),
        _error_code(error_code) {}

        const char* GetFile() const {return _file;}
        const char* GetInfo() const {return _info;}
        int GetLine() const {return _line;}
        int GetErrorCode() const {return _error_code;}
        const char* what() const noexcept override {return _msg;}
    };
}

#endif // _BLOCK_EXCEPTION_H