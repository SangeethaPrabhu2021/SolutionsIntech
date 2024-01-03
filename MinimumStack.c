class MinStack { 
    int currentMinimum; 
    stack<int> elements;
public:
    int Min() { 
        if (elements.empty()) {
            return -1;
        } else {
            return currentMinimum;
        }
    }

    int pop() {
        if (elements.empty()) {
            return -1;
        }

        int poppedValue = elements.top();
        elements.pop();

        if (poppedValue < currentMinimum)
         { 
            int previousMinimum = currentMinimum;
            currentMinimum = 2 * currentMinimum - poppedValue;
            return previousMinimum;
        } else {
            return poppedValue;
        }
    }

    void push(int value) {
        if (elements.empty()) {
            currentMinimum = value;
            elements.push(value);
            return;
        }

        if (value < currentMinimum) { 
            elements.push(2 * value - currentMinimum);
            currentMinimum = value;
        } else {
            elements.push(value);
        }
    }
};
