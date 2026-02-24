#include <App/DepEdge.h>
#include <App/DocumentObject.h>

#include <App/DepEdgePy.h>
#include <App/DepEdgePy.cpp>

using namespace App;

std::string DepEdgePy::representation() const
{
    std::stringstream str;
    auto& [fromObj, fromProp, toObj, toProp] = *getDepEdgePtr();

    if (!fromObj || !toObj) {
        return "<invalid DepEdge>";
    }

    str << fromObj->getFullName() << "." << (fromProp.empty() ? "HEAD" : fromProp)
        << " --> "
        << toObj->getFullName() << "." << (toProp.empty() ? "HEAD" : toProp);
    return {str.str()};
}

Py::Object DepEdgePy::getFromObj() const
{
    auto* obj = getDepEdgePtr()->fromObj;
    if (!obj) {
        return Py::None();
    }
    return Py::Object(obj->getPyObject(), true);
}

Py::String DepEdgePy::getFromProp() const
{
    return {getDepEdgePtr()->fromProp};
}

Py::Object DepEdgePy::getToObj() const
{
    auto* obj = getDepEdgePtr()->toObj;
    if (!obj) {
        return Py::None();
    }
    return Py::Object(obj->getPyObject(), true);
}

Py::String DepEdgePy::getToProp() const
{
    return {getDepEdgePtr()->toProp};
}

PyObject* DepEdgePy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int DepEdgePy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}
