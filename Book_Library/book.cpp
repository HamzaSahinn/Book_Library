#include "book.h"

int book::getBookId() const {
    return book_ID;
}

void book::setBookId(int bookId) {
    book_ID = bookId;
}

const string &book::getBookName() const {
    return book_name;
}

void book::setBookName(const string &bookName) {
    book_name = bookName;
}

const string &book::getWriter() const {
    return writer;
}

void book::setWriter(const string &writer) {
    book::writer = writer;
}

const string &book::getPublisher() const {
    return publisher;
}

void book::setPublisher(const string &publisher) {
    book::publisher = publisher;
}

int book::getPageNumber() const {
    return page_number;
}

void book::setPageNumber(int pageNumber) {
    page_number = pageNumber;
}

float book::getPrice() const {
    return price;
}

void book::setPrice(float price) {
    book::price = price;
}

bool book::compare(book b1) {
    if(book_name.compare(b1.getBookName()) == 0 && book_ID == b1.getBookId())
        return true;
    else
        return false;
}

book::book(int I, string n,string w, string p, int pn, float pr , int ln, int rn ){
    book_ID = I; book_name = n; writer = w; publisher = p; page_number = pn; price = pr; liked_number = ln; read_number = rn;
}

book::book(){

}

int book::getLikedNumber() const {
    return liked_number;
}

void book::setLikedNumber(const int &liked_number) {
    book::liked_number = liked_number;
}

int book::getReadNumber() const {
    return read_number;
}

void book::setReadNumber(const int &read_number) {
    book::read_number = read_number;
}