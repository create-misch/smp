#pragma once

#include <memory>
#include <list>

#include <global.h>

#include <libsmp/model/modelinterface.h>

namespace libsmp {

class PrefixTree;
class Observer;
class PrefixNode;

class ModelMain final : public ModelInterface {
public:
    ModelMain();
    ~ModelMain();

    void addChildObject(const std::string &key) override final;
    void setNameForObject(const std::string &key, const QString &name) override final;
    void setDescriptionForObject(const std::string &key, const QString &description) override final;
    void requestDescriptionForObject(const std::string &key) override final;
    void requestObject(const std::string &key) override final;

    void addObserver(Observer* observer);

private:
    void updateObject(const libsmp::PrefixNode *node);
    void updateDescription(const QString &description);

    std::unique_ptr<PrefixTree> tree_;
    using Observers = std::list<Observer *>;
    Observers observers_;
};

}
