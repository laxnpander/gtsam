// automatically generated by wrap
#include <wrap/matlab.h>
#include <set>
#include <ClassD.h>
typedef boost::shared_ptr<ClassD> Shared;

static std::set<Shared*> collector;

struct Destruct
{
  void operator() (Shared* p)
  {
    collector.erase(p);
  }
};

void cleanup(void) {
  std::for_each( collector.begin(), collector.end(), Destruct() );
}
void mexFunction(int nargout, mxArray *out[], int nargin, const mxArray *in[])
{
  mexAtExit(cleanup);

  const mxArray* input = in[0];
  Shared* self = *(Shared**) mxGetData(input);

  if(self) {
    if(nargin > 1) {
      collector.insert(self);
    }
    else if(collector.erase(self))
      delete self;
  } else {
    int nc = unwrap<int>(in[1]);
    if(nc == 0) {
      self = new Shared(new ClassD());
    }
    collector.insert(self);
    out[0] = mxCreateNumericMatrix(1, 1, mxUINT32OR64_CLASS, mxREAL);
    *reinterpret_cast<Shared**> (mxGetPr(out[0])) = self;
  }
}
