package Entity;

import Entity.GuardProj;
import Entity.InvesteProj;
import Entity.Project;
import javax.annotation.Generated;
import javax.persistence.metamodel.CollectionAttribute;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2019-09-08T14:35:59")
@StaticMetamodel(User.class)
public class User_ { 

    public static volatile SingularAttribute<User, String> userPsw;
    public static volatile CollectionAttribute<User, InvesteProj> investeProjCollection;
    public static volatile CollectionAttribute<User, GuardProj> guardProjCollection;
    public static volatile SingularAttribute<User, String> userTel;
    public static volatile SingularAttribute<User, String> userName;
    public static volatile CollectionAttribute<User, Project> projectCollection;

}