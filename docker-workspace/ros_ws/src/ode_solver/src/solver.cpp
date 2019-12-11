#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose2D.h"

#include <cvodes/cvodes.h>
#include <nvector/nvector_serial.h>
#include <cvodes/cvodes_dense.h>

#include <sstream>

#define TB       RCONST(0.0)  // start time [s]
#define T        RCONST(1.0)  // time horizon [s]

#define RELTOL   RCONST(1.0e-3)
#define ABSTOL   RCONST(1.0e-4)

#define Q0_1     RCONST(10.0)
#define Q0_2     RCONST(0.0)
#define Q0_3     RCONST(M_PI/2)

#define U0_1     RCONST(2.0)  // Initial control
#define U0_2     RCONST(1.0)

#define M        2            // control dimention
#define N        3            // state dimention

typedef struct {
  realtype u[M];
} sPrm;

static int  fun(realtype t, N_Vector q, N_Vector dq, void *prm);

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "solver");
  ros::NodeHandle node;
// ros::Publisher chatter_pub = node.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher chatter_pub = node.advertise <geometry_msgs/Pose2D> ("platform_state", 1);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    geometry_msgs::Pose2D msg;

    std::stringstream ss;


    // msg.x = 0;
    // msg.y = 0;
    // msg.theta = 0;

    // ROS_INFO("%f, %f, %f", msg.x, msg.y, msg.theta);

    chatter_pub.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  //
  // N_Vector  q;
  //
  // realtype *data, t, x, y, phi;
  // void     *cvode_mem;
  // int       err;
  // sPrm      prm;
  //
  // /* Allocate state vector q */
  // q = N_VNew_Serial(N);
  // if(q == NULL){
  //   exit(EXIT_FAILURE);
  // }
  // /* Get pointer to data array in vector q */
  // data = NV_DATA_S(q);
  // /* Set initial state */
  // data[0] = Q0_1;
  // data[1] = Q0_2;
  // data[2] = Q0_3;
  // /* Set control */
  // prm.u[0] = U0_1;
  // prm.u[1] = U0_2;
  // /* Create the solver memory and specify the Adams-Moulton formula and the
  //  * use of a functional iteration */
  // cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
  // if(cvode_mem == NULL){
  //   exit(EXIT_FAILURE);
  // }
  // /* Initialize the integrator memory and specify the user's right hand side
  //  * function in q'=f(t,u), the inital time tb, and the initial dependent
  //  * variable vector q. */
  // err = CVodeInit(cvode_mem, fun, TB, q);
  // /* Specify the scalar relative tolerance and scalar absolute tolerance */
  // err = CVodeSStolerances(cvode_mem, RELTOL, ABSTOL);
  // /* Set the pointer to function parameters */
  // err = CVodeSetUserData(cvode_mem, &prm);
  // /* Specify the CVDENSE dense linear solver */
  // err = CVDense(cvode_mem, N);
  // /* Solve equation */
  // err = CVode(cvode_mem, T, q, &t, CV_NORMAL);
  // x = NV_Ith_S(q,0);
  // y = NV_Ith_S(q,1);
  // phi = NV_Ith_S(q,2);
  // /* Free q vector */
  // N_VDestroy_Serial(q);
  // /* Free integrator memory */
  // CVodeFree(&cvode_mem);


  return 0;
}



int fun(realtype t, N_Vector q, N_Vector dq, void *prm)
{
  realtype  x, y, phi;
  realtype  dx, dy, dphi;
  realtype  u1, u2;
  sPrm     *lprm;

  /* Get actual state */
  x = NV_Ith_S(q,0);
  y = NV_Ith_S(q,1);
  phi = NV_Ith_S(q,2);
  /* Get control signals */
  lprm = (sPrm*)prm;
  u1 = lprm->u[0];
  u2 = lprm->u[1];
  /* Calculate function */
  dx = cos(phi) * u1;
  dy = sin(phi) * u1;
  dphi = u2;
  /* Set output */
  NV_Ith_S(dq,0) = dx;
  NV_Ith_S(dq,1) = dy;
  NV_Ith_S(dq,2) = dphi;
  return 0;
}
