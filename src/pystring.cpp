#include <sstream>
#include "pystring/pystring.h"


namespace pystring {
    std::string capitalize(const std::string &str) {
        std::string::size_type len = str.size();
        std::string res(str);
        if(len > 0) {
            if(std::islower(res[0])) res[0] = static_cast<char>(std::toupper(str[0]));
            for(std::string::size_type i = 1; i < len; i ++) {
                if(std::isupper(res[i])) res[i] = static_cast<char>(tolower(res[i]));
            }
        }
        return res;
    }

    std::string center(const std::string &str, size_t width, char fillchar) {
        std::string::size_type len = str.size();
        std::string res(str);
        if(len >= width) return str;
        std::string::size_type marg = width - len;
        auto left = marg / 2 + (marg & width & 1);
        auto right = marg - left;
        res = std::string(left, fillchar) + str + std::string(right, fillchar);
        return res;
    }

    int count(const std::string & str, const std::string & substr, int start, int end) {
        // using KMP to find the substring
        if(end == -1) end = (int)str.size() - 1;
        std::string s = str.substr(start, end - start + 1);
        std::string::size_type sublen = substr.size();
        std::vector ne(sublen + 1, 0);
        std::string::size_type len = s.size();
        s = ' ' + s;
        for(int i = 1, j = 0; i < sublen; i ++) {
            while(j > 0 && substr[i] != substr[j]) j = ne[j];
            if(substr[i] == substr[j]) j ++;
            ne[i + 1] = j;
        }
        int res = 0;
        for(int i = 1, j = 0; i <= len; i ++) {
            while (j > 0 && s[i] != substr[j]) j = ne[j];
            if (s[i] == substr[j]) j++;
            if (j == sublen) {
                res++;
                j = ne[j];
            }
        }
        return res;
    }
    
    bool endswith(const std::string &str, const std::string &suffix, int start, int end) {
        if(end == -1) end = (int)str.size() - 1;
        std::string s = str.substr(start, end - start + 1);
        std::string::size_type len = s.size();
        std::string::size_type sublen = suffix.size();
        if(len < sublen) return false;
        return s.substr(len - sublen, sublen) == suffix;
    }
    
    std::string expandtabs(const std::string &str, int tabsize) {
        std::string res(str);
        std::string::size_type len = res.size();
        int sum = 0, offset = 0;
        for(auto i = 0; i < len; i ++) {
            if(str[i] == '\t') {
                if(tabsize > 0) {
                    int fillsize = tabsize - sum % tabsize;
                    sum += fillsize;
                    res.replace(i + offset, 1, fillsize, ' ');
                    offset += fillsize - 1;
                } else {
                    res.replace(i + offset, 1, 0, ' ');
                    offset --;
                }
            } else {
                sum ++;
                if(str[i] == '\n' || str[i] == '\r') {
                    sum = 0;
                }
            }
        }
        return res;
    }

    int find(const std::string &str, const std::string &sub, int start, int end) {
        if(end == -1) end = static_cast<int>(str.size()) - 1;
         auto res = str.find(sub, start);
        if(res == std::string::npos || res + sub.size() - 1 > end) return -1;
        return static_cast<int>(res);
    }
    
    int index(const std::string &str, const std::string &sub, int start, int end) {
        int res = find(str, sub, start, end);
        if(res == -1) throw std::out_of_range("substring not found");
        return res;
    }
    
    bool isalnum(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::isalnum(x)) {
                return false;
            }
        }
        return true;
    }
    
    bool isalpha(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::isalpha(x)) return false;
        }
        return true;
    }
    
    bool isdigit(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::isdigit(x)) return false;
        }
        return true;
    }
    
    bool islower(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::islower(x)) return false;
        }
        return true;
    }
    
    bool isspace(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::isspace(x)) return false;
        }
        return true;
    }
    
    bool istitle(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        bool cased = false, previous_is_cased = false;
        for(auto x : str) {
            if(std::isupper(x)) {
                if(previous_is_cased) {
                    return false;
                }
                previous_is_cased = true;
                cased = true;
            }else if(std::islower(x)) {
                if(!previous_is_cased) {
                    return false;
                }
                previous_is_cased = true;
                cased = true;
            }else {
                previous_is_cased = false;
            }
        }
        return cased;
    }
    
    bool isupper(const std::string &str) {
        auto len = str.size();
        if(len == 0) return false;
        for(auto x : str) {
            if(!std::isupper(x)) return false;
        }
        return true;
    }
    
    std::string join(const std::string &str, const std::vector<std::string> &seq) {
        auto seqlen = seq.size();
        if(seqlen == 0) return str;
        auto res = seq[0];
        for(int i = 1; i < seqlen; i ++) {
            res += str + seq[i];
        }
        return res;
    }
    
    std::string ljust(const std::string &str, size_t width, char fillchar) {
        std::string res;
        auto len = str.size();
        if(width < len) return str;
        res = str + std::string(width - len, fillchar);
        return res;
    }
    
    std::string rjust(const std::string &str, size_t width, char fillchar) {
        std::string res;
        auto len = str.size();
        if(width < len) return str;
        res = std::string(width - len, fillchar) + str;
        return res;
    }
    
    std::string lower(const std::string &str) {
        std::string res(str);
        for(auto &x : res) {
            x = static_cast<char>(std::tolower(x));
        }
        return res;
    }
    
    std::string upper(const std::string &str) {
        std::string res(str);
        for(auto x : res) {
            x = static_cast<char>(std::tolower(x));
        }
        return res;
    }
    
    std::string lstrip(const std::string &str, const std::string &chars) {
        // use C++ to implement the lstrip function
        std::string res(str);
        auto len = res.size();
        if(len == 0) return res;
        auto charslen = chars.size();
        if(charslen == 0) {
            for(auto i = 0; i < len; i ++) {
                if(!std::isspace(res[i])) {
                    res = res.substr(i);
                    break;
                }
            }
        } else {
            size_t idx = 0;
            for(auto i = 0; i < len; i ++) {
                if(res[i] != chars[idx]) {
                    if((idx == charslen - 1 || res[i] != chars[idx + 1])) {
                        res = res.substr(i);
                        break;
                    } else idx ++;
                }
            }
        }
        return res;
    }
    
    std::string mul(const std::string &str, int n) {
        if(n <= 0) return "";
        if(n == 1) return str;
        std::ostringstream os;
        for(int i = 0; i < n; i ++) {
            os << str;
        }
        return os.str();
    }
    
    std::vector<std::string> partition(const std::string &str, const std::string &seq) {
        std::vector<std::string> res;
        res.resize(3);
        int pos = str.find(seq);
        if(pos == std::string::npos) {
            res[0] = str;
            res[1] = "";
            res[2] = "";
        } else {
            res[0] = str.substr(0, pos);
            res[1] = seq;
            res[2] = str.substr(pos + seq.size());
        }
        return res;
    }
    
    std::string replace(const std::string &str, const std::string &oldstr, const std::string &newstr, int count) {
        if(count == 0) return str;
        if(count == -1) count = INT_MAX;
        std::string res(str);
        
        auto newlen = newstr.size(), oldlen = oldstr.size();
        auto len = res.size();
        auto pos = res.find(oldstr);
        int sofar = 0;
        while(pos != std::string::npos ) {
            if(sofar >= count) break;
            res.replace(pos, oldlen, newstr);
            sofar ++;
            pos += static_cast<int>(newlen);
            if(oldlen != 0) {
                pos = res.find(oldstr, pos);
            } else {
                pos = res.find(oldstr, pos + 1);
            }
        }
        return res;
    }
}