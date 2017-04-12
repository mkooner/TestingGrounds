// Mehrab Kooner Copyright

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "NextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(Editanywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;
	
	UPROPERTY(Editanywhere, Category = "Blackboard")
		struct FBlackboardKeySelector Waypoint;
};
