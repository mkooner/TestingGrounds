// Mehrab Kooner Copyright

#include "TestingGrounds.h"
#include "NextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get Blackboard and Keys
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//auto NextPoint = BlackboardComp->GetValueAsVector(Waypoint.SelectedKeyName);


	// Get the partrol points and owner
	auto AIOwner = OwnerComp.GetAIOwner()->GetPawn();
		//auto Guard = Cast<APatrollingGuard>(AIOwner);
	UPatrolRoute* Guard = nullptr;
	Guard = AIOwner->FindComponentByClass<UPatrolRoute>();

	if (!Guard) { return EBTNodeResult::Failed; }

	TArray<AActor*> Points = Guard->GetPatrolPoints();

	// Set Patrol Points
	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, Points[Index]);

	// Cycle Index value
	Index = (Index + 1) % Points.Num();

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);


	// Protect Against Empty Patrol Points

	return EBTNodeResult::Succeeded;
}
