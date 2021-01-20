#pragma once

#include "MeshSync/msClient.h" //ClientSettings

namespace MeshSyncClient {

struct BaseSyncSettings {

    ms::ClientSettings client_settings;

    bool sync_meshes = true;
    bool sync_normals = true;
    bool sync_uvs = true;
    bool sync_colors = true;

    bool sync_blendshapes = true;
    bool sync_bones = true;
    bool sync_textures = true;
    bool sync_cameras = true;
    bool sync_lights = true;

    bool make_double_sided = false;    
    bool BakeModifiers = false; 
    bool BakeTransform = false;

    bool flatten_hierarchy = false;

    // cache
    bool ExportSceneCache = false;
};

} // namespace MeshSyncClient
