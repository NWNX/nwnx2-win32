void main() {
	int Time = GetLocalInt(OBJECT_SELF, "MOD_TIMEOFDAY");
	WriteTimestampedLogEntry("ModTime: " +IntToString(Time));
}