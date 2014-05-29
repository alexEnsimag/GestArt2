class Swipe extends XnVSwipeDetector 
{
  XnVSwipeDetector swipeDetector;
  Server server;

  public Swipe(XnVSessionManager sessionManager, Server server)
  {
    this.server = server;
    swipeDetector = new XnVSwipeDetector();
    swipeDetector.RegisterSwipeLeft(this);
    swipeDetector.RegisterSwipeRight(this);
    sessionManager.AddListener(swipeDetector);
  }

  void onSwipeLeft(float velocity, float angle){
    ws.broadcast("left "+velocity+" "+angle);
    println("SWIPELEFT");
  }

  void onSwipeRight(float velocity, float angle){
    ws.broadcast("right "+velocity+" "+angle);
    println("SWIPERIGHT");
  }
  
  void onSwipeUp(float velocity, float angle){
    ws.broadcast("SWIPEUP "+velocity+" "+angle);
    println("SWIPEUP");
  }
  
  void onSwipeDown(float velocity, float angle){
    ws.broadcast("SWIPEDOWN "+velocity+" "+angle);
    println("SWIPEDOWN");
  }
}
