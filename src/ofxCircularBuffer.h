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
    
    virtual void setSize(int sz){
        buf.clear();
        buf.resize(sz);
    }
    
    virtual bool setCurPos(int idx){
        if(idx<0 || idx>=buf.size())return false;
        curPos = idx;
        return true;
    }
    
    virtual void setValue(T val, int idx){
        buf[idx] = val;
    }
    
    virtual void setValue(T val){
        buf[curPos] = val;
    }
    
    virtual void posUp(){
        curPos++;
        if(curPos>=buf.size())curPos=0;
    }
    
    virtual void posDown(){
        curPos--;
        if(curPos<0)curPos=buf.size()-1;
    }
    
    
    virtual BufferIterator begin(){
        return BufferIterator(buf.begin()+curPos);
    }
    
    virtual BufferIterator end(){
        int pos = curPos-1;
        if(pos<0)pos = buf.size()-1;
        return BufferIterator(buf.begin()+pos);
    }
    
    virtual BufferIterator nthFromBegin(int n){
        int nth = curPos+n;
        while(nth>=buf.size()){
            nth -= buf.size();
        }
        return BufferIterator(buf.begin()+nth);
    }
    
    virtual T getValue(){return buf[curPos];}
    virtual T getValue(int idx){return buf[idx];}
    
    virtual int getCurPos(){return curPos;}
    virtual int getSize(){return buf.size();}
protected:
    vector<T> buf;
    int curPos;
};