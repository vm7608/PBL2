#ifndef QUESTION_H
#define QUESTION_H
class Question {
    protected:
        int score;
        virtual void Setup() = 0;
    public:
        Question();
        Question(int);
        Question(const Question &a);
        virtual ~Question();
        virtual int Show() = 0;
};

Question::Question() {

}

Question::Question(int score) {
    this->score = score;
}

Question::Question(const Question &a) {
    score = a.score;
}

Question::~Question() {}

#endif