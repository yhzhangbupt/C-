package Entity;

import Entity.GuardProj;
import Entity.InvesteProj;
import Entity.User;
import javax.annotation.Generated;
import javax.persistence.metamodel.CollectionAttribute;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2019-09-08T14:35:59")
@StaticMetamodel(Project.class)
public class Project_ { 

    public static volatile SingularAttribute<Project, Integer> projId;
    public static volatile SingularAttribute<Project, String> projCity;
    public static volatile SingularAttribute<Project, Integer> projCondition;
    public static volatile SingularAttribute<Project, String> applDate;
    public static volatile SingularAttribute<Project, String> projName;
    public static volatile SingularAttribute<Project, String> projAddr;
    public static volatile SingularAttribute<Project, String> applicantIDcard;
    public static volatile CollectionAttribute<Project, GuardProj> guardProjCollection;
    public static volatile SingularAttribute<Project, User> userTel;
    public static volatile SingularAttribute<Project, String> applicantName;
    public static volatile SingularAttribute<Project, String> projRegion;
    public static volatile SingularAttribute<Project, Integer> projProvince;
    public static volatile SingularAttribute<Project, Integer> projClass;
    public static volatile CollectionAttribute<Project, InvesteProj> investeProjCollection;
    public static volatile SingularAttribute<Project, String> projDepict;
    public static volatile SingularAttribute<Project, String> applicantMail;

}