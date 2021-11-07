#include <cstring>
#include <ostream>

#ifndef SIXTHASEMPROJECT_STR_HPP
#define SIXTHASEMPROJECT_STR_HPP

class Str;
class _str;

class _str {
    char *m_pszData;
    int m_nCount;

    friend class Str;
    _str() {
        this->m_pszData = new char[1]{0};
        this->m_nCount = 1;
    }

    _str(const char *p) {
        this->m_nCount = 1;
        m_pszData = new char[strlen(p) + 1];
        strcpy(this->m_pszData, p);
    }

    ~_str() {
        delete []m_pszData;
    }

    void AddRef() { this->m_nCount++; };
    void Release() {
        if (--this->m_nCount == 0) delete this;
    }
};

class Str {
    _str *m_pStr;
public:
    Str() {
        this->m_pStr = new _str;
    }

    Str(const char *p) {
        this->m_pStr = new _str(p);
    }

    Str(const Str &s) {
        this->m_pStr = s.m_pStr;
        this->m_pStr->AddRef();
    }

    ~Str() {
        this->m_pStr->Release();
    }


    Str &operator = (const Str &s) {
        if (this != &s) {
            s.m_pStr->AddRef();
            this->m_pStr->Release();
            this->m_pStr = s.m_pStr;
        }

        return *this;
    }

    Str &operator += (const Str &s) {
        int length = this->len() + s.len();
        if (s.len() != 0) {
            _str *pstrTmp = new _str;
            delete [] pstrTmp->m_pszData;

            pstrTmp->m_pszData = new char [length + 1];
            strcpy(pstrTmp->m_pszData, m_pStr->m_pszData);
            strcat(pstrTmp->m_pszData, s.m_pStr->m_pszData);

            this->m_pStr->Release();
            this->m_pStr = pstrTmp;
        }

        return *this;
    }

    int len() const {
        return strlen(m_pStr->m_pszData);
    }

    int replace(char ch_old, char ch_new) {
        int result = 0;
        bool modified = false;
        char *p = this->m_pStr->m_pszData;
        char *new_str = nullptr;
        for (int i = 0; *p != 0; p++, i++) {
            if (*p == ch_old) {
                if (!modified) {
                    modified = true;
                    _str *pstrTmp = new _str;
                    strcpy(pstrTmp->m_pszData, this->m_pStr->m_pszData);
                    this->m_pStr->Release();
                    this->m_pStr = pstrTmp;
                }

                *(this->m_pStr->m_pszData + i) = ch_new;
                result++;
            }
        }

        return result;
    };

    void print() {
        std::cout << this->m_pStr->m_pszData << std::endl;
    }
};

#endif //SIXTHASEMPROJECT_STR_HPP
