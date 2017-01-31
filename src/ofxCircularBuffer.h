//
//  ofxCircularBuffer.h
//
//  Created by enrico<nausea>viola on 1/30/17.
// 
//

#pragma once
#include "ofMain.h"



template<typename T>
class ofxCircularBuffer{
public:
    
    typedef typename std::vector<T>::iterator BufferIterator;
    
    ofxCircularBuffer(){
        curPos = 0;
    }
    
    void setSize(int sz){
        buf.clear();
        buf.resize(sz);
    }
    
    bool setCurPos(int idx){
        if(idx<0 || idx>=buf.size())return false;
        curPos = idx;
        return true;
    }
    
    void setValue(T val, int idx){
        buf[idx] = val;
    }
    
    void setValue(T val){
        buf[curPos] = val;
    }
    
    void posUp(){
        curPos++;
        if(curPos>=buf.size())curPos=0;
    }
    
    void posDown(){
        curPos--;
        if(curPos<0)curPos=buf.size()-1;
    }
    
    
    BufferIterator & begin(){
        return BufferIterator(buf.begin()+curPos);
    }
    
    BufferIterator & end(){
        int pos = curPos-1;
        if(pos<0)pos = buf.size()-1;
        return BufferIterator(buf.begin()+pos);
    }
    
    BufferIterator nthFromBegin(int n){
        int nth = curPos+n;
        while(nth>=buf.size()){
            nth -= buf.size();
        }
        return BufferIterator(buf.begin()+nth);
    }
    
    T getValue(){return buf[curPos];}
    T getValue(int idx){return buf[idx];}
    
    int getCurPos(){return curPos;}
    int getSize(){return buf.size();}
protected:
    vector<T> buf;
    int curPos;
};