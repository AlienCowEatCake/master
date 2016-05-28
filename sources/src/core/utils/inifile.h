#if !defined(UTILS_INIFILE_H_INCLUDED)
#define UTILS_INIFILE_H_INCLUDED

#include <list>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

#include "strings.h"

namespace core { namespace utils {

/**
 * @brief Класс для работы с ini-файлами
 */
class inifile
{
public:
    /**
     * @brief Конструктор по-умолчанию
     */
    inifile();

    /**
     * @brief Конструктор с именем входного файла
     * @param[in] filename имя входного файла
     */
    inifile(const std::string & filename);

    /**
     * @brief Загрузка ini-файла
     * @param[in] filename имя входного файла
     * @return true - файл успешно считан, false - возникли ошибки
     */
    bool load(const std::string & filename);

    /**
     * @brief Статус, разобран ли ini-файл
     * @return true - файл успешно разобран, false - возникли ошибки
     */
    bool good() const;

    /**
     * @brief Получить значение параметра с именем "parameter" в секции "section" подсекции "subsection"
     * @param[in] section секция, в которой нужно искать
     * @param[in] subsection подсекция, в которой нужно искать
     * @param[in] parameter параметр, который нужно искать
     * @param[in] fallback значение по-умолчанию, которое возвращается, если искомый параметр не найден
     * @return значение параметра или fallback, если параметр не найден
     * @note Функция для типа string
     */
    template<typename U>
    std::string get(const std::string & section, const U & subsection, const std::string & parameter,
                    const std::string & fallback) const;

    /**
     * @brief Получить значение параметра с именем "parameter" в секции "section" подсекции "subsection"
     * @param[in] section секция, в которой нужно искать
     * @param[in] subsection подсекция, в которой нужно искать
     * @param[in] parameter параметр, который нужно искать
     * @param[in] fallback значение по-умолчанию, которое возвращается, если искомый параметр не найден
     * @return значение параметра или fallback, если параметр не найден
     * @note Функция для типа char *, его приводим к std::string
     */
    template<typename U>
    std::string get(const std::string & section, const U & subsection, const std::string & parameter,
                    const char * fallback) const;

    /**
     * @brief Получить значение параметра с именем "parameter" в секции "section" подсекции "subsection"
     * @param[in] section секция, в которой нужно искать
     * @param[in] subsection подсекция, в которой нужно искать
     * @param[in] parameter параметр, который нужно искать
     * @param[in] fallback значение по-умолчанию, которое возвращается, если искомый параметр не найден
     * @return значение параметра или fallback, если параметр не найден
     * @note Функция для типа bool, нужно сделать дополнительное преобразование yes|true|1 -> true
     */
    template<typename U>
    bool get(const std::string & section, const U & subsection, const std::string & parameter,
             const bool & fallback) const;

    /**
     * @brief Получить значение параметра с именем "parameter" в секции "section" подсекции "subsection"
     * @param[in] section секция, в которой нужно искать
     * @param[in] subsection подсекция, в которой нужно искать
     * @param[in] parameter параметр, который нужно искать
     * @param[in] fallback значение по-умолчанию, которое возвращается, если искомый параметр не найден
     * @return значение параметра или fallback, если параметр не найден
     * @note Обобщенная функция для типов, которые не являются типами bool или string
     */
    template<typename T, typename U>
    T get(const std::string & section, const U & subsection, const std::string & parameter,
          const T & fallback) const;

    /**
     * @brief Получть список из всех подсекций секции "section"
     * @param[in] section секция, в которой нужно искать подсекции
     * @param[in] type фиктивный указатель, из которого определяется тип возвращаемого результата
     * @return список из всех подсекций секции "section"
     * @note type используется как флаг типа, передавать в него нужно, например (size_t*)(NULL)
     */
    template<typename T>
    std::list<T> enumerate(const std::string & section, const T * type) const;

    /**
     * @brief Проверить, что в файле нет никаких секций, кроме секций из списка "whitelist"
     * @param[in] whitelist список разрешенных секций
     * @return true - все секции присутствуют в "whitelist", false - есть неразрешенная секция
     * @note Полезно для контроля опечаток, так как в остальных местах это штатная ситуация
     */
    bool check_sections(const std::list<std::string> & whitelist) const;

    /**
     * @brief Проверить, что во всех подсекциях секции нет параметров не из белого списка
     * @param[in] section секция, для которой будет выполнена проверка
     * @param[in] whitelist список разрешенных параметров
     * @return true - все параметры присутствуют в "whitelist", false - есть неразрешенный параметр
     * @note Полезно для контроля опечаток, так как в остальных местах это штатная ситуация
     */
    bool check_parameters(const std::string & section, const std::list<std::string> & whitelist) const;

protected:

    /**
     * @brief Костыльный контейнер подсекции для исправления багов MSVC
     * @note https://msdn.microsoft.com/en-us/library/074af4b6.aspx
     */
    struct subsection_t
    {
        std::map<std::string, std::string> _;
    };

    /**
     * @brief Костыльный контейнер секции для исправления багов MSVC
     * @note https://msdn.microsoft.com/en-us/library/074af4b6.aspx
     */
    struct section_t
    {
        std::map<std::string, subsection_t> _;
    };

    /**
     * @brief Статус, разобран ли входной конфиг
     */
    bool m_status;

    /**
     * @brief Конетейнер значений параметров, сгруппированных в подсекции, сгруппированные в секции
     */
    std::map<std::string, section_t> m_values;

    /**
     * @brief Получить значение параметра с именем "parameter" в секции "section" подсекции "subsection"
     * @param[in] section секция
     * @param[in] subsection подсекция
     * @param[in] parameter параметр
     * @return значение параметра или NULL, если такого параметра нет
     */
    const std::string * get_internal(const std::string & section, const std::string & subsection,
                                     const std::string & parameter) const;

    /**
     * @brief Преобразование подсекции в строковое представление
     * @param[in] subsection подсекция
     * @return строковое представление подсекции
     * @note Если это строка, то она уже итак задана как надо
     */
    std::string subsection_to_str(const std::string & subsection) const;

    /**
     * @brief Преобразование подсекции в строковое представление
     * @param[in] subsection подсекция
     * @return строковое представление подсекции
     * @note Если это char *, то просто соберем из него строку
     */
    std::string subsection_to_str(const char * subsection) const;

    /**
     * @brief Преобразование подсекции в строковое представление
     * @param[in] subsection подсекция
     * @return строковое представление подсекции
     */
    template<typename T>
    std::string subsection_to_str(const T & subsection) const;
};

}} // namespace core::utils

#endif // UTILS_INIFILE_H_INCLUDED
