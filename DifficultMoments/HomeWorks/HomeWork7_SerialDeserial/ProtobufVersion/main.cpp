#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "protoVariant.pb.h"


using namespace std;

// Task 3
//============================================================================
namespace Task3
{
    class IRepository
    {
    public:
        virtual void Open() = 0; // бинарная десериализация в файл
        virtual void Save() = 0; // бинарная сериализация в файл
        virtual ~IRepository() {};
    };

    class IMethods
    {
    public:
        virtual double GetAverageScore(const protoVariant::FullName& name) = 0;
        virtual std::string GetAllInfo(const protoVariant::FullName& name) = 0;
        virtual std::string GetAllInfo() = 0;
        virtual ~IMethods() {};
    };

    class StudentsGroup : public IRepository, public IMethods
    {
    private:
        std::vector<protoVariant::Student> m_students;
    public:
        void add_student(const protoVariant::Student& s)
        {
            m_students.push_back(s);
        }

        double GetAverageScore(const protoVariant::FullName& name)
        {
            auto it = std::find_if(m_students.begin(), m_students.end(), [&](const protoVariant::Student& s)
                {
                    return tie(s.name().name(), s.name().surname(), s.name().patronymic()) ==
                        tie(name.name(), name.surname(), name.patronymic());
                });

            if (it == m_students.end())
            {
                return 0.0;
            }

            return it->average();
        }

        std::string GetAllInfo(const protoVariant::FullName& name)
        {
            auto it = std::find_if(m_students.begin(), m_students.end(), [&](const protoVariant::Student& s)
                {
                    return tie(s.name().name(), s.name().surname(), s.name().patronymic()) ==
                        tie(name.name(), name.surname(), name.patronymic());
                });

            if (it == m_students.end())
            {
                return {};
            }

            std::string temp = "Name: " + it->name().name() + ' ' + it->name().surname() + ' ' + it->name().patronymic() + '\n';
            temp += "Grades: ";
            for (int i = 0; i < it->grades().size(); ++i)
            {
                temp += std::to_string(it->grades(i)) + "; ";
            }
            temp += '\n';
            temp += "GPA: " + std::to_string(it->average()) + "\n\n";

            return temp;
        }

        std::string GetAllInfo()
        {
            std::string temp;

            std::for_each(m_students.begin(), m_students.end(), [&](const protoVariant::Student& s)
                {
                    temp += GetAllInfo(s.name());
                });

            return temp;
        }

        void Save()
        {
            std::ofstream out("data.bin", std::ios_base::binary);
            auto size = m_students.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            std::for_each(m_students.begin(), m_students.end(), [&](const protoVariant::Student& s)
                {
                    s.SerializeToOstream(&out);
                });
            out.close();
        }

        void Open()
        {
            std::ifstream in("data.bin", std::ios_base::binary);
            size_t size = 0;
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            while (size--)
            {
                protoVariant::Student s;
                s.ParseFromIstream(&in);
                m_students.push_back(std::move(s));
            }
            in.close();
        }

        virtual ~StudentsGroup() {};
    };
}
//============================================================================


int main() 
{
    // Task 1_2
    //===============================================
    protoVariant::FullName fn;
    fn.set_name("Ivanov");
    fn.set_surname("Ivan");
    fn.set_patronymic("Ivanovich");

    protoVariant::Student s;
    *s.mutable_name() = fn;
    s.add_grades(5);
    s.add_grades(2);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.add_grades(4);
    s.add_grades(3);
    s.set_average(accumulate(s.grades().begin(), s.grades().end(), 0) / s.grades().size());

    protoVariant::StudentsGroup sg;
    *sg.add_students() = s;

    std::ofstream out("student.bin", ios_base::binary);
    sg.SerializeToOstream(&out);
    out.close();

    protoVariant::StudentsGroup new_sg;
    ifstream in("student.bin", ios_base::binary);
    if (new_sg.ParseFromIstream(&in))
    {
        cout << new_sg.students(0).name().surname() << endl;
        cout << new_sg.students(0).average() << endl;
    }
    else
    {
        cout << "Error!" << endl;
    }
    in.close();
    //===============================================

    // Task 3
    //===============================================
    /*Task3::StudentsGroup sg1;
    sg1.add_student(s);
    sg1.Save();

    Task3::StudentsGroup new_sg1;
    new_sg1.Open();
    std::cout << new_sg1.GetAllInfo(fn) << std::endl;*/
    //===============================================
}
