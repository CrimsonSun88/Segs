/*
 * SEGS - Super Entity Game Server
 * http://www.segs.io/
 * Copyright (c) 2006 - 2018 SEGS Team (see AUTHORS.md)
 * This software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.
 */

#pragma once
#include <memory>
#include <string>
#include "Common/GameData/Contact.h"

class QString;
struct MapClientSession;
struct MapInstance;

class ScriptingEngine
{
public:
    ScriptingEngine();
    ~ScriptingEngine();
    void registerTypes();
    int loadAndRunFile(const QString &path);
    void callFuncWithMapInstance(MapInstance *mi, const char *name, int arg1);
    void callFuncWithClientContext(MapClientSession *client,const char *name,int arg1);
    void callFuncWithClientContext(MapClientSession *client,const char *name,int arg1, glm::vec3 loc);
    void callFuncWithClientContext(MapClientSession *client, const char *name, const char *arg1, glm::vec3 loc);
    void callFunc(const char *name,int arg1);
    void callFunc(const char *name,int arg1, glm::vec3 loc);
    void callFunc(const char *name, const char *arg1, glm::vec3 loc);
    void callFunc(const char *name, std::vector<Contact> contact_list);
    void updateMapInstance(MapInstance * instance);
    void updateClientContext(MapClientSession * client);
    int runScript(const QString &script_contents,const char *script_name="unnamed script");
    int runScript(MapClientSession *client,const QString &script_contents,const char *script_name="unnamed script");
    bool setIncludeDir(const QString &path);
private:
#ifdef SCRIPTING_ENABLED
    struct ScriptingEnginePrivate;
    std::unique_ptr<ScriptingEnginePrivate> m_private;
#endif
};
