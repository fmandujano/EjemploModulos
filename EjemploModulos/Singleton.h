#pragma once

//singleton tomado de https://codereview.stackexchange.com/questions/173929/modern-c-singleton-template

template < typename T >
class Singleton {
public:
    static T& GetInstance() {
        static MemGuard g; // clean up on program end
        if (!m_instance) {
            m_instance = new T();
        }
        return *m_instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton) = delete;

protected:
    Singleton() { };
    virtual ~Singleton() { }

private:
    inline static T* m_instance = nullptr;

    class MemGuard {
    public:
        ~MemGuard() {
            delete m_instance;
            m_instance = nullptr;
        }
    };
};

