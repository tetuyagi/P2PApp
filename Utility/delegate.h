#ifndef DELEGATE_H
#define DELEGATE_H

#include <QNetworkReply>
#include "delegatebase.h"

template<typename R, typename... Args>
class Delegate;

template<typename R, typename T, typename... Args>
class Delegate<R(T, Args...)> : public DelegateBase<R(Args...)>
{
public:

    virtual ~Delegate(){}

    using EventFunc = R(T::*)(Args...);

    virtual R operator()(Args... args){
        return (m_instance->*m_func)(args...);
    }

    void set(T *instance, EventFunc func){
        m_instance = instance;
        m_func = func;
    }

    static DelegateBase<R, Args...>* createDelegator(T *instance, EventFunc func){
        Delegate *delegate = new Delegate();
        delegate->set(instance, func);
        return delegate;
    }

private:
    Delegate(){}

    T *m_instance;
    EventFunc *m_func;
};

#endif // DELEGATE_H
