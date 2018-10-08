#ifndef CrabWalkGroup_H
#define CrabWalkGroup_H

#include <Commands/CommandGroup.h>
#include <WPILib.h>

class CrabWalkGroup : public CommandGroup {
private:
	bool isLeftWalk;
public:
	CrabWalkGroup(bool isLeft);
};

#endif  // CrabWalkGroup_H
