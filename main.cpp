#include "header.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Use 2 parametrs!";
        return 0;
    }
    std::cout
            << "    \t\t-Instruction-\n"
               "\t-The program works correctly if the correct operations are entered!-\n"
               "\t-Calculator with brackets can:\n"
               "+,-,*,/,^,sqrt,sin,cos,tan,ctg,exp.-\n";

    std::string str = argv[1]; // считываем введённую строку
    str += "#";

    // Создаём приоритетность операций
    std::unordered_map<int, std::vector<std::string> > operators = {{0, {"#"}},
                                                                    {1, {"(",   ")"}},
                                                                    {2, {"+",   "-"}},
                                                                    {3, {"*",   "/"}},
                                                                    {4, {"^",   "sqrt"}},
                                                                    {5, {"sin", "cos", "tan", "ctg", "exp"}}};
    // Создам массив всех цифр, чтобы сверять со следующим значением элемента строки
    std::vector<char> cifra = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int buf_prioritet = 0;
    std::string buf_operacia;
    std::string buf_chislo;
    std::stack<float> numbers;
    std::stack<std::string> action;
    std::stack<int> prior_pered;

    //Перебираю все символы в строке
    for (size_t symbol = 0; symbol != str.size(); symbol++) {
        char sym = str[symbol];
        //Если символ — цифра или точка
        if ((std::find(cifra.begin(), cifra.end(), sym) != cifra.end()) || (sym == '.')) {
            //Добавляем эту цифру в стоку "chislo", которая определит число не из одного символа
            buf_chislo.push_back(sym);
            // Если следующий символ — не цифра и не точка
            if ((std::find(cifra.begin(), cifra.end(), str[symbol + 1]) == cifra.end()) && (str[symbol + 1] != '.')) {
                // Мы убеждаемся, что это конец числа и добавляем его в стек чисел "numbers"
                numbers.push(float(std::stod(buf_chislo)));
                buf_chislo = ""; //Обнуляем, чтобы собрать число заново
            }
        } else { //Если символ — не цифра
            //Добавляем этот символ в стоку "operaсia", которая определит операцию не из одного символа
            buf_operacia.push_back(sym);
            if (buf_operacia == "pi"){
                numbers.push(std::numbers::pi);
                buf_operacia ="";
            }
            for (const auto &prioritet: operators) {
                if ((prioritet.second.end() != std::find(prioritet.second.begin(), prioritet.second.end(),
                                                         buf_operacia))) {
                    if (!action.empty()) {
                        while ((prioritet.first <= buf_prioritet) )  {
                            Magic(numbers, action, buf_prioritet, buf_operacia, prior_pered);
                        }
                    }
                    buf_prioritet = prioritet.first;

                    if (buf_operacia != ")") {
                        action.push(buf_operacia);
                        prior_pered.push(prioritet.first);
                    }

                    buf_operacia = "";
                    break;
                }
            }
        }
    }
    if (!buf_operacia.empty()) {
        std::cerr << "The operations are entered incorrectly!";
        return 0;
    }

    //Проверка для себя — вывод элементов стека
    action.pop();
    for (size_t j = 0, n = numbers.size(); j != n; j++) {
        std::cout << numbers.top() << ' ';
        numbers.pop();
    }
    std::cout << std::endl;
    for (size_t w = 0, q = action.size(); w != q; w++) {
        std::cout << action.top() << ' ';
        action.pop();
    }
}
