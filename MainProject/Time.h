#pragma once
class Time
{
public:
	static double DeltaTime();
	static double FramesPerSecond();
	static void Update();
private:
	static double b_CurrentTime;
	static double b_LastTime;
};

