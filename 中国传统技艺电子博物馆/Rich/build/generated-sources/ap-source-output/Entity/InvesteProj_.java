package Entity;

import Entity.InvesteProjPK;
import Entity.Project;
import Entity.User;
import javax.annotation.Generated;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2019-09-08T14:35:59")
@StaticMetamodel(InvesteProj.class)
public class InvesteProj_ { 

    public static volatile SingularAttribute<InvesteProj, Double> funding;
    public static volatile SingularAttribute<InvesteProj, InvesteProjPK> investeProjPK;
    public static volatile SingularAttribute<InvesteProj, Project> project;
    public static volatile SingularAttribute<InvesteProj, User> user;

}