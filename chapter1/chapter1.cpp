#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
class chapter1 
{
public:
    chapter1(std::string) ;
    std::string changeSTR() ;
    bool palindrom() ;
    bool unique() ;
    bool permutation(std::string,std::string) ;
    bool oneAway(std::string,std::string) ;
    std::string StringCompression() ;
    std::vector<std::vector<int>> RotateMatrix(std::vector<std::vector<int>> ) ;
    std::vector<std::vector<int>> MatrixNULL(std::vector<std::vector<int>> ) ;
    bool StringRotation(std::string,std::string) ;
private:
    std::string str ;
} ;

chapter1::chapter1(std::string str) 
{
    this->str = str ;
}


std::string chapter1::changeSTR()
{
    std::string tmp ;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ' ') {
            tmp += "%20" ;
        }  else {
            tmp.push_back(str[i]) ;
        }
    }
    return tmp ;
}

void foo() 
{
    std::cerr << "barev dzez" ;
    abort() ;
}


bool chapter1::palindrom()
{
    for(int i = 0 ; i < str.size() ; ++i) 
    {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32 ;
        } else if(str[i] == ' ') {
            str.erase(str.begin() + i) ;
        }
    }
    std::multiset<char> s ;
    for(int i = 0; i < str.size(); ++i) {
        s.emplace(str[i]) ;
    }
    char ch = *s.begin() ;
    int count {};
    int kent_count {};
    for(std::multiset<char>::iterator it1 = s.begin() ;it1 != s.end() ; ++it1) 
    {
        
        if(ch == *it1)
        {
            ++count ;
        } else {
            if (count % 2 == 1) { 
                
                ++kent_count ;
                if(kent_count == 2) return false ;
            }
            ch = *it1 ;
            count = 0 ;
            --it1 ;
        }

    }
    if(kent_count == 1 && count % 2 == 1) return false ;
    return true ;

}
bool chapter1::unique() 
{
    std::string tmp ;
    std::unique_copy(str.begin(),str.end(),std::back_inserter(tmp)) ;
    return tmp.size() == str.size() ;
}

bool chapter1::permutation(std::string str1 , std::string str2) 
{
    std::sort(str1.begin(),str1.end()) ;
    std::sort(str2.begin(),str2.end()) ;
    return str1 == str2 ;
}
bool chapter1::oneAway(std::string str1,std::string str2)  
{
    int s = abs(str1.size() - str2.size()) ;
    if(s > 1) { return false ; }
    if((s == 1) && (str1.size() > str2.size())) {
        for(int i = 0; i < str1.size() ; ++i) {
            if(str1[i] != str2[i]) 
            {
                str2.insert(str2.begin() + i,str1[i]) ;
                break ;
            }
        }
        if(str2 != str1) return false ;
    } else if((s == 1) && (str2.size() > str1.size())) {
        for(int i = 0; i < str2.size() ; ++i) {
            if(str1[i] != str2[i]) 
            {
                str1.insert(str1.begin() + i,str2[i]) ;
                break ;
            }
        }
        if(str2 != str1) return false ;
    } else {
        for(int i = 0; i < str1.size() ; ++i) {
            if(str1[i] != str2[i]) 
            {
                str2[i] = str1[i] ;
                break ;
            }
        }
        if(str2 != str1) return false ;
    }

    return true ;
}
std::string chapter1::StringCompression()
{
    std::string tmp ;
    int count {0} ;
    char ch = str[0] ;
    for(int i = 0 ; i <= str.size() ; ++i)
    {
        if(str[i] == ch) {
            ++count ;
        } else {
            tmp.push_back(ch) ;
            tmp += std::to_string(count) ;
            ch = str[i] ;
            count = 0 ;
            --i ;
        }
    }
    return tmp ;
}

std::vector<std::vector<int>> chapter1::RotateMatrix(std::vector<std::vector<int>> matrix)
{
    std::vector<std::vector<int>> tmp(matrix.size());
    for(int i = 0; i < matrix.size(); ++i) {
        tmp[i].resize(matrix.size()) ;
    }
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix.size(); ++j) {
            tmp[j][matrix.size() - i - 1] = matrix[i][j] ;
        }
    }
    return tmp ;
}
std::vector<std::vector<int>> chapter1::MatrixNULL(std::vector<std::vector<int>> matrix) 
{
    std::vector<std::pair<int,int>> pvec ;
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            if(matrix[i][j] == 0) {
                pvec.push_back(std::make_pair(i,j)) ;
            }
        }
    }
    for(auto i : pvec) {
        for(int k = 0 ; k <= matrix.size(); ++k) {
            matrix[i.first][k] = 0 ;
        }
        for(int k = 0 ; k < matrix.size(); ++k) {
            matrix[k][i.second] = 0 ;
        }
    }
    return matrix ;
}

bool chapter1::StringRotation(std::string str1, std::string str2) 
{
    if(str1.size() != str2.size()) return false ;
    for(int i = 0 ; i < str1.size() ; ++i) 
    {
        str2.push_back(str2[0]) ;
        str2.erase(0,1) ;
        if (str1 == str2) {
            return true ;
        }

    }
    return false ;
}
