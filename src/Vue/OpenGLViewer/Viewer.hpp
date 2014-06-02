#ifndef DEF_VIEWER
#define DEF_VIEWER



class Viewer {
	public:
		Viewer();
		~Viewer();
		void launch();
	private:
		Squelette *squelette;
};

#endif
