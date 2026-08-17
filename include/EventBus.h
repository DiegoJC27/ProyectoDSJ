#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class EventListener;

struct EventData {
	std::string type = "";
	std::string name = "";
	std::string tag = "";
	int intVal = 0;
	float floatVal = 0.0f;
	bool boolVal = false;
};

class EventBus
{
public:
	static EventBus& GetInstance()
	{
		static EventBus instance;
		return instance;
	}

	EventBus() = default;
	~EventBus() = default;	

	int BindListener(const std::string& event, EventListener* listener);
	void UnBindListener(const std::string& event, int id );
	void Fire(const std::string& event, EventData eData = {});

private:

	struct Listener {
		int id = 0;
		EventListener* eventListener = nullptr;
	};

	int nextID = 0;
	std::unordered_map<std::string, std::vector<Listener>> subscribers;

};

class EventListener {
public:
	~EventListener() = default;
	virtual void OnEvent(EventData eData) = 0;

protected:
	void Listen(const std::string& event);

private:
	struct Subscrition {
		std::string event;
		int id;
	};

	std::vector<Subscrition> subscriptions;
};

