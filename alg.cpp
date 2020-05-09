            stack.pop();

} 
            int result = calculate(num2, num1, ch);
            stack.push(result);
            int res = calculate(num2, num1, ch);
            stack.push(res);
        }

    }
