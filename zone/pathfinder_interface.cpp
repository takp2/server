#include "../common/seperator.h"
#include "client.h"
#include "pathfinder_null.h"
#include "pathfinder_nav_mesh.h"
#include "pathfinder_waypoint.h"
#include "../common/global_define.h"
#include "../common/eqemu_logsys.h"
#include <sys/stat.h>

IPathfinder *IPathfinder::Load(const std::string &zone) {
	struct stat statbuffer;
	std::string navmesh_path = StringFormat("Maps/%s.nav", zone.c_str());
	if (stat(navmesh_path.c_str(), &statbuffer) == 0) {
		return new PathfinderNavmesh(navmesh_path);
	}

	std::string old_navmesh_path = StringFormat("Maps/%s.path", zone.c_str());
	if (stat(old_navmesh_path.c_str(), &statbuffer) == 0) {
		return new PathfinderWaypoint(old_navmesh_path);
	}

	return new PathfinderNull();
}