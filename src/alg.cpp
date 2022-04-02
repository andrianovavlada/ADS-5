// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char ch) {
    if (ch == '(') {
        return 0;
    }
    if (ch == ')') {
        return 1;
    }
    if (ch == '+') {
        return 2;
    }
    if (ch == '-') {
        return 2;
    }
    if (ch == '*') {
        return 3;
    }
    if (ch == '/') {
        return 3;
    } else {
    return -1;
    }
}

std::string infx2pstfx(std::string inf) {
    std::string post;
    TStack <char, 100> stack1;
for (int i = 0; i < inf.size(); i++) {
    if (prior(inf[i]) == -1) {
        post.push_back(inf[i]);
        post.push_back(' ');
    } else if (prior(inf[i]) == 0 || stack1.isEmpty()) {
            stack1.push(inf[i]);
        } else if (prior(inf[i]) > prior(stack1.get())) {
            stack1.push(inf[i]);
    } else if (prior(inf[i]) == 1) {
            while (prior(stack1.get()) != 0) {
                post.push_back(stack1.get());
                post.push_back(' ');
                stack1.pop();
            }
            stack1.pop();
        } else {
            while (prior(inf[i]) <= prior(stack1.get())) {
                post.push_back(stack1.get());
                post.push_back(' ');
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
    }
}
while (!stack1.isEmpty()) {
    post.push_back(stack1.get());
    post.push_back(' ');
    stack1.pop();
}
for (int i = 0; i < post.size(); i++) {
    if (post[post.size() - 1] == ' ')
      post.erase(post.size() - 1);
  }
  return post;
}

int calcul(char ch, int a, int b) {
    if ('+' == ch) {
        return a + b;
    }
    if ('-' == ch) {
        return a - b;
    }
    if ('*' == ch) {
        return a * b;
    }
    if ('/' == ch && b != 0) {
        return a / b;
    } else {
    return -1;
    }
}

int eval(std::string pref) {
  // добавьте код
TStack <int, 100> stack2;
  for (int i = 0; i < pref.size(); i++) {
    if (prior(pref[i]) == -1) {
      stack2.push(pref[i] - '0');
    } else if (prior(pref[i]) <= 3) {
      int b = stack2.get();
      stack2.pop();
      int a = stack2.get();
      stack2.pop();
      stack2.push(calcul(pref[i], a, b));
    }
  }
  int znachenie = stack2.get();
  return znachenie;
}
