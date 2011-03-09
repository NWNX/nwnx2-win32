// is run before a player actually leaves the server
// here it is still possible to get their name, area, etc
// OBJECT_SELF is the player about to leave
void main() {
	WriteTimestampedLogEntry(GetName(OBJECT_SELF));
	WriteTimestampedLogEntry(GetName(GetArea(OBJECT_SELF)));
}